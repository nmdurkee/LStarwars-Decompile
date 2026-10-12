/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x416c90; label: FUN_00416c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00416c90(void)

{
  uint uVar1;
  int in_EAX;
  undefined4 uVar2;
  int in_EDX;
  int unaff_ESI;
  
  uVar1 = *(uint *)(&DAT_008034cc + in_EAX * 0xc);
  if ((((uVar1 & 1) == 0) &&
      ((((uVar1 & 0x4000) == 0 || ((*(byte *)(*(int *)(unaff_ESI + 0x54) + 4) & 0x10) != 0)) ||
       ((*(uint *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x90) & 0x8000) != 0)))) &&
     (((uVar1 & 0x8000) == 0 ||
      ((*(char *)(unaff_ESI + 0x280) != -1 && (*(float *)(in_EDX + 4) <= 0.0)))))) {
    return 0;
  }
  FUN_004381e0();
  if (((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0) && (DAT_007f3b14 == -1)) {
    uVar2 = FUN_0046c6e0();
    FUN_0046d270(uVar2,0,0,0,unaff_ESI + 0x80,0,0x40000000,0xffffffff,0x3f800000,0x49f42400);
  }
  FUN_00437390();
  return 1;
}

