package com.geekfaner.shineengine;

import android.opengl.GLSurfaceView;
import android.util.Log;

import javax.microedition.khronos.opengles.GL10;
import javax.microedition.khronos.egl.EGLConfig;

/**
 * Created by Administrator on 2017/7/4.
 */

public class SRenderer implements GLSurfaceView.Renderer {

    // ===========================================================
    // Constants
    // ===========================================================

    private final static long NANOSECONDSPERSECOND = 1000000000L;
    private final static long NANOSECONDSPERMICROSECOND = 1000000L;

    // The final animation interval which is used in 'onDrawFrame'
    private static long sAnimationInterval = (long) (1.0 / 60 * SRenderer.NANOSECONDSPERSECOND);

    private int mScreenWidth;
    private int mScreenHeight;

    // ===========================================================
    // Fields
    // ===========================================================

    private long mLastTickInNanoSeconds;

    // ===========================================================
    // Methods for/from SuperClass/Interfaces
    // ===========================================================

    @Override
    public void onSurfaceCreated(final GL10 GL10, final EGLConfig EGLConfig) {
        Log.e("SRenderer:Created", "1");
        SRenderer.nativeInit(this.mScreenWidth, this.mScreenHeight);
        this.mLastTickInNanoSeconds = System.nanoTime();
    }

    @Override
    public void onSurfaceChanged(final GL10 GL10, final int width, final int height) {
        Log.e("SRenderer:Changed", "1");
        SRenderer.nativeOnSurfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(final GL10 gl) {
        /*
         * No need to use algorithm in default(60 FPS) situation,
         * since onDrawFrame() was called by system 60 times per second by default.
         */
        if (SRenderer.sAnimationInterval <= 1.0 / 60 * SRenderer.NANOSECONDSPERSECOND) {
            SRenderer.nativeRender();
        } else {
            final long now = System.nanoTime();
            final long interval = now - this.mLastTickInNanoSeconds;

            if (interval < SRenderer.sAnimationInterval) {
                try {
                    Thread.sleep((SRenderer.sAnimationInterval - interval) / SRenderer.NANOSECONDSPERMICROSECOND);
                } catch (final Exception e) {
                }
            }
            /*
             * Render time MUST be counted in, or the FPS will slower than appointed.
            */
            this.mLastTickInNanoSeconds = System.nanoTime();
            SRenderer.nativeRender();
        }
    }

    private static native void nativeInit(final int width, final int height);
    private static native void nativeOnSurfaceChanged(final int width, final int height);
    private static native void nativeRender();
}
