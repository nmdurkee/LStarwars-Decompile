/* Ghidra analysis pseudocode, not original source.
 * ev_7c1f0ecd29c800f910a33bdaa344f8ed50b7b31113b7bd43cf044ecf7b83bf10
 * Entry: 0x6e9fc2; label: FUN_006e9fc2
 */

void FUN_006e9fc2(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_006f01bc(DAT_0297c19c);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x006e9fd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  FUN_006f8568(2);
                    /* WARNING: Subroutine does not return */
  __invoke_watson(param_1,param_2,param_3,param_4,param_5);
}

