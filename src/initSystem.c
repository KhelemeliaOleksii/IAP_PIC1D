int InitSystem (int needContinue) {
    if (!needContinue) {
        system("rm *.dat");
        return 1;
    } 
    // do some procedures
    return 1;        
}