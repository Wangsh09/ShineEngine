package com.geekfaner.shineengine;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class ShineActivity extends AppCompatActivity {

    private int[] mGLContextAttrs = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.mGLContextAttrs = getGLContextAttrs();

        setContentView(R.layout.activity_shine);

    // Example of a call to a native method
    TextView tv = (TextView) findViewById(R.id.sample_text);
    tv.setText(mGLContextAttrs[0]+" "+mGLContextAttrs[1]+" "+mGLContextAttrs[2]+" "+mGLContextAttrs[3]+" "+mGLContextAttrs[4]+" "+mGLContextAttrs[5]);
    }

    //native method,call GLViewImpl::getGLContextAttrs() to get the OpenGL ES context attributions
    private static native int[] getGLContextAttrs();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
