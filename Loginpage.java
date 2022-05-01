public class MainActivity extends Activity {
	Button b1,b2;
	EditText ed1,ed2;

	TextView tx1;
	int counter = 3;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		b1 = (Button) findViewById(R.id.button);
		ed1 = (EditText)findViewById(R.id.editText);
		ed2 = (EditText)findViewById(R.id.editText2);

		b2 = (Button)findViewById(R.id.button2);
		tx1 = (TextView) findViewById(R.id.textView3);
		tx1.setVisibility(View.GONE);

		bl.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				if(ed1.getText().toString().equals("admin") &&
						ed2.getText().toString().equals("admin")) {
					
					Toast.makeText(getApplicationContext(),
							text: "Login successful", Toast.LENGTH_SHORT).show();
				}else{
					Toast.makeText(getApplicationContext(), text: "Wrong Credentials", Toast.LENGTH_SHORT).show();

		
						tx1.setVisibility(View.VISIBLE);
					tx1.setBackgroundColor (Color.RED);
					counter--;
					tx1.setText(Integer.toString (counter));

					if (counter == 0) {
						b1.setEnabled(false);
					}
				}
			}
		});

		b2.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) { finish(); }
		});
	}
}

