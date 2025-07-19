public class MyMTAObject {
	//
	// TODO: Write appropriate member variable and constructor
	// to store a HeavyCompute implementation
	private final HeavyCompute heavyCompute;

	private final Object certlock = new Object();

	public MyMTAObject(HeavyCompute heavyCompute) {
		this.heavyCompute = heavyCompute;
	}


	//
	// TODO: Write appropriate implementation of doCompute()
	// NOTE: This method will be called from multiple threads.
	//
	public void doCompute() {
		String cert;

		synchronized (certlock) {
			cert = heavyCompute.getCertificate();
		}

		heavyCompute.compute(cert);
	}
	// You have to first collect a certificate for computation.
	// Ensure that no two threads get the same certificate.
	//
	// Then call compute() with the certificate.
	// Write your code in a way to maximize parallelization.
	//
}
