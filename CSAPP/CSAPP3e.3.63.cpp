long switch_prob(long x, long n) { 
    long result = x;
    switch(n) {
    	case 60:
//    		result = 8*x;
//    		break;
//    	case 61:
//		    result = 75 + x;
//		    break;
    	case 62:
    		result = 8*x;
    		break;
    	case 63:
    		result = x>>3;
    		break;
    	case 64:
    		result = x<<4;
    		result = result -x;
    		x = result;
    	case 65:
		    x = x*x;
    	default:
    		result =  75 + x;
        /* Fill in code here */
    }
    return result;
}
