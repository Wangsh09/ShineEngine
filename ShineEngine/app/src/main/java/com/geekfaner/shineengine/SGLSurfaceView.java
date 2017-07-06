package com.geekfaner.shineengine;

import android.opengl.GLSurfaceView;
import android.content.Context;
import android.util.AttributeSet;

/**
 * Created by Administrator on 2017/7/3.
 */

public class SGLSurfaceView extends GLSurfaceView {

    private static SGLSurfaceView mSGLSurfaceView;
    private SRenderer mSRenderer;

    // ===========================================================
    // Constructors
    // ===========================================================

    public SGLSurfaceView(final Context context) {
        super(context);

        this.initView();
    }

    public SGLSurfaceView(final Context context, final AttributeSet attrs) {
        super(context, attrs);

        this.initView();
    }

    protected void initView() {

        SGLSurfaceView.mSGLSurfaceView = this;

        //Patrick : TODO
        /*
        this.setFocusableInTouchMode(true);

        Cocos2dxGLSurfaceView.sCocos2dxTextInputWraper = new Cocos2dxTextInputWrapper(this);

        Cocos2dxGLSurfaceView.sHandler = new Handler() {
            @Override
            public void handleMessage(final Message msg) {
                switch (msg.what) {
                    case HANDLER_OPEN_IME_KEYBOARD:
                        if (null != Cocos2dxGLSurfaceView.this.mCocos2dxEditText && Cocos2dxGLSurfaceView.this.mCocos2dxEditText.requestFocus()) {
                            Cocos2dxGLSurfaceView.this.mCocos2dxEditText.removeTextChangedListener(Cocos2dxGLSurfaceView.sCocos2dxTextInputWraper);
                            Cocos2dxGLSurfaceView.this.mCocos2dxEditText.setText("");
                            final String text = (String) msg.obj;
                            Cocos2dxGLSurfaceView.this.mCocos2dxEditText.append(text);
                            Cocos2dxGLSurfaceView.sCocos2dxTextInputWraper.setOriginText(text);
                            Cocos2dxGLSurfaceView.this.mCocos2dxEditText.addTextChangedListener(Cocos2dxGLSurfaceView.sCocos2dxTextInputWraper);
                            final InputMethodManager imm = (InputMethodManager) Cocos2dxGLSurfaceView.mCocos2dxGLSurfaceView.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
                            imm.showSoftInput(Cocos2dxGLSurfaceView.this.mCocos2dxEditText, 0);
                            Log.d("GLSurfaceView", "showSoftInput");
                        }
                        break;

                    case HANDLER_CLOSE_IME_KEYBOARD:
                        if (null != Cocos2dxGLSurfaceView.this.mCocos2dxEditText) {
                            Cocos2dxGLSurfaceView.this.mCocos2dxEditText.removeTextChangedListener(Cocos2dxGLSurfaceView.sCocos2dxTextInputWraper);
                            final InputMethodManager imm = (InputMethodManager) Cocos2dxGLSurfaceView.mCocos2dxGLSurfaceView.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
                            imm.hideSoftInputFromWindow(Cocos2dxGLSurfaceView.this.mCocos2dxEditText.getWindowToken(), 0);
                            Cocos2dxGLSurfaceView.this.requestFocus();
                            // can take effect after GLSurfaceView has focus
                            ((Cocos2dxActivity)Cocos2dxGLSurfaceView.mCocos2dxGLSurfaceView.getContext()).hideVirtualButton();
                            Log.d("GLSurfaceView", "HideSoftInput");
                        }
                        break;
                }
            }
        };
        */
    }

    public void setSRenderer(final SRenderer renderer) {
        this.mSRenderer = renderer;
        this.setRenderer(this.mSRenderer);
    }
}
