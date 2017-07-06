package com.geekfaner.shineengine;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;

import android.view.ViewGroup;
import android.graphics.PixelFormat;
import android.util.Log;

import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLContext;

public class ShineActivity extends AppCompatActivity {

    private SGLSurfaceView mGLSurfaceView = null;
    private int[] mGLContextAttrs = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.mGLContextAttrs = getGLContextAttrs();

        this.init();

        //Patrick : Duplicated.
        /*
        setContentView(R.layout.activity_shine);

    // Example of a call to a native method
    TextView tv = (TextView) findViewById(R.id.sample_text);
    tv.setText(mGLContextAttrs[0]+" "+mGLContextAttrs[1]+" "+mGLContextAttrs[2]+" "+mGLContextAttrs[3]+" "+mGLContextAttrs[4]+" "+mGLContextAttrs[5]);
    */
    }

    //native method,call GLViewImpl::getGLContextAttrs() to get the OpenGL ES context attributions
    private static native int[] getGLContextAttrs();

    protected ResizeLayout mFrameLayout = null;
    // ===========================================================
    // Methods
    // ===========================================================
    public void init() {

        // FrameLayout
        ViewGroup.LayoutParams framelayout_params =
                new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,
                        ViewGroup.LayoutParams.MATCH_PARENT);

        mFrameLayout = new ResizeLayout(this);

        mFrameLayout.setLayoutParams(framelayout_params);

        //Patrick : Duplicated
        /*
        // EditText layout
        ViewGroup.LayoutParams edittext_layout_params =
                new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,
                        ViewGroup.LayoutParams.WRAP_CONTENT);
        EditText edittext = new EditText(this);
        edittext.setLayoutParams(edittext_layout_params);

        mFrameLayout.addView(edittext);
        */

        // Cocos2dxGLSurfaceView
        this.mGLSurfaceView = this.onCreateView();

        // ...add to FrameLayout
        mFrameLayout.addView(this.mGLSurfaceView);

        //Patrick : TODO
        // Switch to supported OpenGL (ARGB888) mode on emulator
        /*
        if (isAndroidEmulator())
            this.mGLSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        */

        this.mGLSurfaceView.setSRenderer(new SRenderer());

        // Set framelayout as the content view
        setContentView(mFrameLayout);
    }

    public SGLSurfaceView onCreateView() {
        SGLSurfaceView glSurfaceView = new SGLSurfaceView(this);
        //this line is need on some device if we specify an alpha bits
        if(this.mGLContextAttrs[3] > 0) glSurfaceView.getHolder().setFormat(PixelFormat.TRANSLUCENT);

        // use custom EGLConfigureChooser and EGLContextFactory
        SEGLConfigChooser chooser = new SEGLConfigChooser(this.mGLContextAttrs);
        glSurfaceView.setEGLConfigChooser(chooser);
        glSurfaceView.setEGLContextFactory(new ContextFactory());
        return glSurfaceView;
    }

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }


// ===========================================================
// Inner and Anonymous Classes
// ===========================================================

    private class SEGLConfigChooser implements GLSurfaceView.EGLConfigChooser
    {
        private int[] mConfigAttributes;
        private  final int EGL_OPENGL_ES2_BIT = 0x04;
        private  final int EGL_OPENGL_ES3_BIT = 0x40;
        public SEGLConfigChooser(int redSize, int greenSize, int blueSize, int alphaSize, int depthSize, int stencilSize)
        {
            mConfigAttributes = new int[] {redSize, greenSize, blueSize, alphaSize, depthSize, stencilSize};
        }
        public SEGLConfigChooser(int[] attributes)
        {
            mConfigAttributes = attributes;
        }

        @Override
        public EGLConfig chooseConfig(EGL10 egl, EGLDisplay display)
        {
            int[][] EGLAttributes = {
                    {
                            // GL ES 2 with user set
                            EGL10.EGL_RED_SIZE, mConfigAttributes[0],
                            EGL10.EGL_GREEN_SIZE, mConfigAttributes[1],
                            EGL10.EGL_BLUE_SIZE, mConfigAttributes[2],
                            EGL10.EGL_ALPHA_SIZE, mConfigAttributes[3],
                            EGL10.EGL_DEPTH_SIZE, mConfigAttributes[4],
                            EGL10.EGL_STENCIL_SIZE, mConfigAttributes[5],
                            EGL10.EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
                            EGL10.EGL_NONE
                    },
                    {
                            // GL ES 2 by default
                            EGL10.EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
                            EGL10.EGL_NONE
                    }
            };

            EGLConfig result = null;
            for (int[] eglAtribute : EGLAttributes) {
                result = this.doChooseConfig(egl, display, eglAtribute);
                if (result != null)
                    return result;
            }

            Log.e(DEVICE_POLICY_SERVICE, "Can not select an EGLConfig for rendering.");
            return null;
        }

        private EGLConfig doChooseConfig(EGL10 egl, EGLDisplay display, int[] attributes) {
            EGLConfig[] configs = new EGLConfig[1];
            int[] matchedConfigNum = new int[1];
            boolean result = egl.eglChooseConfig(display, attributes, configs, 1, matchedConfigNum);
            if (result && matchedConfigNum[0] > 0) {
                return configs[0];
            }
            return null;
        }
    }

    private static class ContextFactory implements GLSurfaceView.EGLContextFactory {

        private static int EGL_CONTEXT_CLIENT_VERSION = 0x3098;

        public EGLContext createContext(
                EGL10 egl, EGLDisplay display, EGLConfig eglConfig) {

            int[] attributes = {EGL_CONTEXT_CLIENT_VERSION, 2, EGL10.EGL_NONE };
            EGLContext context = egl.eglCreateContext(
                    display, eglConfig, EGL10.EGL_NO_CONTEXT, attributes);

            return context;
        }

        public void destroyContext(EGL10 egl, EGLDisplay display, EGLContext context) {
            egl.eglDestroyContext(display, context);
        }
    }
}

