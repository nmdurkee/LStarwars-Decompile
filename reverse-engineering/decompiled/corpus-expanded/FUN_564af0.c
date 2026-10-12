/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x564af0; label: FUN_00564af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00564af0(float param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined4 auStack_40 [12];
  float fStack_10;
  float fStack_c;
  
  if (DAT_0095070c != 0) {
    if ((param_2 == 0) && (DAT_0095075c != (code *)0x0)) {
      (*DAT_0095075c)(&param_1);
    }
    if (0.0 < param_1) {
      puVar6 = &DAT_009505ec;
      do {
        iVar3 = FUN_005cfac0(puVar6);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)FUN_005d0330(puVar6);
          puVar7 = auStack_40;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar7 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar7 = puVar7 + 1;
          }
          FUN_005ff7a0(puVar6,auStack_40,param_1);
          fVar2 = fStack_c;
          fVar1 = fStack_10;
          uVar5 = FUN_0054fa60();
          uVar5 = uVar5 & 0xffff;
          iVar3 = 3;
          do {
            fStack_10 = fVar1 + (float)(&DAT_029899a0)[(uVar5 & 0xffff) >> 1] * 0.01;
            fStack_c = (float)(&DAT_029899a0)[(int)((uVar5 & 0xffff) + 0x4000) >> 1 & 0x7fff] * 0.01
                       + fVar2;
            FUN_005ff7a0(puVar6,auStack_40,param_1);
            uVar5 = uVar5 + 0x5555;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        puVar6 = puVar6 + 0xc;
      } while ((int)puVar6 < 0x95061c);
    }
  }
  return;
}

