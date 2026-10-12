/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x596530; label: FUN_00596530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00596530(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  DAT_00955b38 = FUN_005f7420();
  FUN_005c6cc0(DAT_00955b38,5,2);
  FUN_005c6c90(DAT_00955b38,0,0x3f59999a);
  FUN_005c6c90(DAT_00955b38,1,0x40600000);
  FUN_005c6c90(DAT_00955b38,2,0x3ecccccd);
  FUN_005c6c90(DAT_00955b38,3,0x3e4ccccd);
  FUN_005c6c90(DAT_00955b38,0xe,0x38d1b717);
  FUN_005c6c90(DAT_00955b38,0xb,0x38d1b717);
  FUN_005c6c90(DAT_00955b38,0x12,0x38d1b717);
  FUN_005c6c90(DAT_00955b38,0x10,0x38d1b717);
  iVar4 = DAT_00955b38;
  *(undefined4 *)(DAT_00955b38 + 0x800) = 0;
  FUN_005b79d0(iVar4 + 0x7c0,0xc2700000,0x42700000,0xc2700000,0x42700000,0,0x43960000);
  DAT_00955b3c = FUN_005f7420();
  FUN_005c6cc0(DAT_00955b3c,5,2);
  FUN_005c6c90(DAT_00955b3c,0,0x3e800000);
  FUN_005c6c90(DAT_00955b3c,1,0x40600000);
  FUN_005c6c90(DAT_00955b3c,2,0x3f59999a);
  FUN_005c6c90(DAT_00955b3c,3,0x3e4ccccd);
  FUN_005c6c90(DAT_00955b3c,0xe,0x38d1b717);
  FUN_005c6c90(DAT_00955b3c,0xb,0x38d1b717);
  iVar4 = DAT_00955b3c;
  *(undefined4 *)(DAT_00955b3c + 0x800) = 0;
  FUN_005b79d0(iVar4 + 0x7c0,0xc2700000,0x42700000,0xc2700000,0x42700000,0,0x43960000);
  piVar1 = (int *)(DAT_00955b3c + 0x808);
  if (*piVar1 == 0) {
    piVar2 = (int *)(DAT_00955b3c + 0x70c);
    iVar4 = 0;
    if (0 < *piVar2) {
      puVar3 = (undefined4 *)(DAT_00955b3c + 0x2b8);
      do {
        *puVar3 = puVar3[-1];
        puVar3[0x11] = puVar3[0x10];
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 0xe0;
      } while (iVar4 < *piVar2);
    }
    *piVar1 = 1;
    return;
  }
  *piVar1 = 1;
  return;
}

