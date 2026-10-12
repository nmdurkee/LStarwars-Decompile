/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x483840; label: FUN_00483840
 */

void FUN_00483840(void)

{
  undefined4 uVar1;
  int iVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float10 extraout_ST0;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar2 = 0;
  pfVar3 = (float *)&DAT_0087a650;
  puVar4 = &DAT_009253b0;
  do {
    FUN_0054a810(pfVar3 + -1);
    if ((((&DAT_008668cc)[iVar2] == '\0') || ((&DAT_0087a6cc)[iVar2] == '\0')) ||
       ((*(byte *)((int)puVar4 + 0x5a) & 0x20) == 0)) {
      uVar6 = *puVar4;
      uVar1 = 0;
      uVar7 = 0;
    }
    else {
      fVar5 = (float10)0;
      if ((float10)*pfVar3 <= fVar5) {
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_006e6b90();
        fVar5 = extraout_ST0;
      }
      if ((fVar5 < (float10)pfVar3[2]) || (*(char *)(pfVar3 + 3) != '\0')) {
        uVar7 = 1;
        uVar6 = *puVar4;
      }
      else {
        uVar7 = 0;
        uVar6 = *puVar4;
      }
    }
    FUN_006de6d0(uVar6,uVar7,uVar1);
    puVar4 = puVar4 + 0x18;
    iVar2 = iVar2 + 1;
    pfVar3 = pfVar3 + 5;
  } while ((int)puVar4 < 0x925470);
  return;
}

