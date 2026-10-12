/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e933d; label: FUN_006e933d
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e933d(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint in_EAX;
  uint extraout_ECX;
  uint uVar1;
  short in_FPUControlWord;
  
  uVar1 = in_EAX;
  if (in_FPUControlWord != 0x27f) {
    in_EAX = FUN_006f68f5();
    uVar1 = extraout_ECX;
  }
  if ((uVar1 & 0x7ff00000) != 0x7ff00000) {
                    /* WARNING: Subroutine does not return */
    __fload_withFB();
  }
  if ((in_EAX & 0xfffff) == 0 && param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    __fload_withFB();
  }
                    /* WARNING: Subroutine does not return */
  __fload_withFB();
}

