/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4c9d10; label: FUN_004c9d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004c9d10(undefined2 param_1)

{
  int iVar1;
  int *unaff_EDI;
  
  if (*unaff_EDI != 0) {
    return 1;
  }
  iVar1 = FUN_005e4d00(1);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x54) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x58) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x70) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0xb4) = 0x1000;
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffefe2 | 0xe022;
  *(undefined2 *)(iVar1 + 0x74) = param_1;
  FUN_005e4b00(iVar1);
  *unaff_EDI = iVar1;
  return 1;
}

