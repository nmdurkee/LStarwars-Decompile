/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bce60; label: FUN_004bce60
 */

void FUN_004bce60(undefined2 param_1)

{
  int iVar1;
  int unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_005b4670();
  local_c = 0x3e888ce7;
  FUN_005b4900();
  FUN_005b4f70();
  FUN_005b4900();
  iVar1 = unaff_ESI + 0x40;
  FUN_005b4670(iVar1,param_1);
  local_c = 0xbe888ce7;
  FUN_005b4900(iVar1,&local_c);
  FUN_005b4f70(iVar1,*(undefined2 *)(unaff_ESI + 0xa0));
  FUN_005b4900(iVar1,unaff_ESI + 0x90);
  return;
}

