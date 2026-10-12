/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57d270; label: FUN_0057d270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057d270(int param_1,int param_2,float *param_3)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  float *pfVar6;
  float10 fVar7;
  float local_40 [5];
  float local_2c;
  float local_1c;
  float local_c;
  
  if ((*(byte *)(param_1 + 0x58) & 0x10) != 0) {
    fVar7 = (float10)FUN_005b3c50(param_3 + 0xc,PTR_DAT_008021b4 + 0xe8,0);
    if (fVar7 < (float10)_DAT_00951c00) {
      fVar7 = (float10)FUN_005506f0(0,param_3 + 0xc,0x40a00000,0xffffffff);
      fVar1 = (float)fVar7;
      if (((fVar1 != 2e+06) && (uVar2 = FUN_0067a600(), uVar2 < 0x21)) &&
         (((&DAT_008034cc)[uVar2 * 0xc] & 2) != 0)) {
        iVar3 = FUN_0055f450();
        pfVar6 = local_40;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *pfVar6 = *param_3;
          param_3 = param_3 + 1;
          pfVar6 = pfVar6 + 1;
        }
        local_40[1] = -local_40[1];
        local_2c = -local_2c;
        local_1c = -local_1c;
        local_c = fVar1 - (local_c - fVar1);
        uVar4 = FUN_005cfa50(param_2);
        iVar5 = FUN_0057a3c0(uVar4);
        if (((iVar5 == -1) || (iVar5 = FUN_0057a390(iVar5), iVar5 == -1)) ||
           (iVar3 = iVar5 * 0x10 + *(int *)(iVar3 + 0x2ac0), iVar3 == 0)) {
          iVar3 = param_2;
        }
        FUN_005d4690(0);
        FUN_005f33b0(iVar3,local_40);
        FUN_005d46b0();
      }
    }
  }
  return;
}

