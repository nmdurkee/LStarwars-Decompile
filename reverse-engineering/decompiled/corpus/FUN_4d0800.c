/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d0800; label: FUN_004d0800
 */

void FUN_004d0800(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  int unaff_ESI;
  float10 fVar3;
  
  puVar1 = (undefined4 *)(unaff_ESI + 0x34);
  FUN_005b3800(puVar1,unaff_ESI + 0x1c,unaff_ESI + 0x10);
  uVar2 = FUN_005be2d0(*puVar1,*(undefined4 *)(unaff_ESI + 0x3c));
  *(undefined2 *)(unaff_ESI + 0x44) = uVar2;
  fVar3 = (float10)FUN_005bec80(puVar1);
  *(float *)(unaff_ESI + 0x40) = (float)fVar3;
  FUN_005b3830(puVar1,puVar1,1.0 / (float)fVar3);
  *(undefined1 *)(unaff_ESI + 0x46) = 1;
  *(undefined1 *)(unaff_ESI + 0x47) = 1;
  return;
}

