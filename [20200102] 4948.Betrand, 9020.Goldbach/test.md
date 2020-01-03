~~~cpp
	arr[1] = 0;

	for (int i = 2; i <= 548; i++) {
		if (arr[i] == 1) {
			for (int k = i+i; k < 300000; k += i) {
				arr[k] = 0;
			}
		}
	}
~~~
