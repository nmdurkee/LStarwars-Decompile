/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d3620; label: FUN_004d3620
 */

void FUN_004d3620(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_004d3150(param_1);
  iVar2 = FUN_0054fa60();
  if (iVar2 < 0x8000) {
    uVar1 = 0x3ecccccd;
  }
  else {
    uVar1 = 0xbecccccd;
  }
  FUN_00549de0(PTR_DAT_008021b4,uVar1,2,0);
  FUN_0054a910(0x3f333333,0,0,0);
  return;
}

