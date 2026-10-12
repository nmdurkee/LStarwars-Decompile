/* Ghidra analysis pseudocode, not original source.
 * ev_2f277248dc33480f063e4f0d474d621052bdb6108e7bcd5536ed18fa967ce013
 * Entry: 0x6f8280; label: __d_inttype
 */

/* Library Function - Single Match
    __d_inttype
   
   Library: Visual Studio 2005 Release */

undefined4 __d_inttype(double param_1)

{
  uint uVar1;
  float10 fVar2;
  undefined8 extraout_var;
  
  uVar1 = __fpclass(param_1);
  if ((uVar1 & 0x90) == 0) {
    fVar2 = (float10)__frnd(param_1,extraout_var);
    if (fVar2 == (float10)param_1) {
      param_1 = param_1 * 0.5;
      fVar2 = (float10)__frnd();
      if (fVar2 == (float10)param_1) {
        return 2;
      }
      return 1;
    }
  }
  return 0;
}

