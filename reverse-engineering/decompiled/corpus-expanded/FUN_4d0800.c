/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d0800; label: FUN_004d0800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

