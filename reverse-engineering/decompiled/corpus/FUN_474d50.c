/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x474d50; label: FUN_00474d50
 */

undefined4 FUN_00474d50(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    piVar2 = &DAT_007f939c;
    do {
      if (((int *)*piVar2 != (int *)0x0) && (*(int *)*piVar2 == param_1)) {
        return 1;
      }
      piVar1 = piVar2 + 2;
      piVar2 = piVar2 + 0xf;
    } while (*piVar1 != 0);
  }
  return 0;
}

