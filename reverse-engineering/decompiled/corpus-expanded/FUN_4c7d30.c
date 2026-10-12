/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c7d30; label: FUN_004c7d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c7d30(int param_1)

{
  byte bVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  float10 fVar9;
  float10 fVar10;
  int local_78;
  int local_74;
  undefined1 local_64 [12];
  int local_58 [5];
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined4 local_40;
  
  local_74 = 0;
  if (0 < *(int *)(param_1 + 0x5064)) {
    iVar6 = *(int *)(param_1 + 0x5060) + 0x50;
    do {
      iVar4 = FUN_0054fa60();
      bVar1 = *(byte *)(iVar6 + 0x1a);
      *(float *)(iVar6 + 0x1c) = (float)iVar4 * 1.5259022e-05 * 0.1 + 0.8;
      if (((bVar1 & 1) == 0) || ((bVar1 & 2) == 0)) {
        fVar9 = (float10)0;
        *(byte *)(iVar6 + 0x1a) = bVar1 & 0xfb;
      }
      else {
        if ((bVar1 & 4) == 0) {
          iVar4 = *(int *)(iVar6 + 0x30);
          piVar7 = &DAT_00802cd8;
          piVar8 = local_58;
          for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar8 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar8 = piVar8 + 1;
          }
          local_58[0] = *(int *)(DAT_00926c20 + **(short **)(iVar4 + 8) * 4);
          local_58[1] = iVar6 + 0x34;
          local_58[3] = 0x3f800000;
          local_44 = 0xff;
          local_43 = 0xff;
          local_42 = 0;
          local_41 = 0x30;
          local_40 = 0x87;
          FUN_00560b60(local_58);
          uVar3 = 0x3f800000;
        }
        else {
          local_78 = 0;
          do {
            iVar4 = (&DAT_0093d7f0)[local_78];
            if ((((iVar4 != 0) && ((*(uint *)(iVar4 + 0x1fc) & 1) != 0)) &&
                ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) &&
               (*(short *)(iVar4 + 0x1064) == *(short *)(*(int *)(iVar6 + 0x30) + 0x14))) {
              fVar9 = (float10)FUN_005b3c50(iVar4 + 0x80,iVar6 + 0x34,0);
              if (fVar9 < (float10)0.49000006914138794) {
                FUN_005b3800(local_64,iVar4 + 0x80,iVar6);
                fVar9 = (float10)FUN_005b39e0(local_64,iVar6 + 0x24);
                fVar10 = (float10)FUN_005bec80(local_64);
                fVar2 = *(float *)(iVar4 + 0x1dc) + 0.3;
                if ((float)fVar10 * (float)fVar10 - (float)fVar9 * (float)fVar9 < fVar2 * fVar2)
                break;
              }
            }
            local_78 = local_78 + 1;
          } while (local_78 < 8);
          if (local_78 == 8) {
            *(byte *)(iVar6 + 0x1a) = *(byte *)(iVar6 + 0x1a) & 0xfb;
          }
          uVar3 = 0;
        }
        fVar9 = (float10)FUN_0054fad0(*(undefined4 *)(iVar6 + 0x20),uVar3,_DAT_00925018 * 3.0);
      }
      *(float *)(iVar6 + 0x20) = (float)fVar9;
      local_74 = local_74 + 1;
      iVar6 = iVar6 + 0x94;
    } while (local_74 < *(int *)(param_1 + 0x5064));
  }
  return;
}

