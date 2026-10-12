/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a22b0; label: FUN_005a22b0
 */

void FUN_005a22b0(ushort *param_1)

{
  ushort uVar1;
  void *_Dst;
  
  _Dst = *(void **)(param_1 + 2);
  uVar1 = *param_1;
  _memset(_Dst,0,(uint)*param_1 << 7);
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(void **)(param_1 + 2) = _Dst;
  *param_1 = uVar1;
  FUN_005a2250();
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 2);
  return;
}

