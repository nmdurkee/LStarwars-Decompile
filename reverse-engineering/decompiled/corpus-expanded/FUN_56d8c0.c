/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56d8c0; label: FUN_0056d8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d8c0(int param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (((DAT_00802818 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802818)) ||
     (iVar5 = *(int *)(param_1 + 0x798), iVar5 == 0)) {
    if (DAT_00802814 != -1) {
      iVar5 = (int)*(char *)(param_1 + 0x7b5);
      if (iVar5 == DAT_00802814) {
        iVar5 = *(int *)(param_1 + 0x798);
        if ((((iVar5 == 0) || (*(float *)(param_1 + 0x188) < *(float *)(iVar5 + 0x14))) ||
            (*(float *)(iVar5 + 0x28) < *(float *)(param_1 + 0x17c))) ||
           (fVar2 = *(float *)(param_1 + 0x80) - *(float *)(iVar5 + 0x10),
           fVar3 = *(float *)(param_1 + 0x88) - *(float *)(iVar5 + 0x18),
           *(float *)(iVar5 + 0x2c) < fVar2 * fVar2 + fVar3 * fVar3)) {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
          return;
        }
      }
      else if (((*(uint *)(PTR_PTR_007fb0e4 + iVar5 * 0x10 + 8) & 0x400000) == 0) &&
              (iVar4 = *(int *)(param_2 + 0x4690), iVar4 != 0)) {
        iVar6 = 0;
        if (0 < *(int *)(param_2 + 0x4694)) {
          while ((((bVar1 = *(byte *)(iVar4 + 0x34), (bVar1 & 2) == 0 || ((bVar1 & 1) == 0)) ||
                  ((bVar1 & 4) != 0)) ||
                 ((((*(float *)(param_1 + 0x188) < *(float *)(iVar4 + 0x14) ||
                    (*(float *)(iVar4 + 0x28) < *(float *)(param_1 + 0x17c))) ||
                   (fVar2 = *(float *)(param_1 + 0x80) - *(float *)(iVar4 + 0x10),
                   fVar3 = *(float *)(param_1 + 0x88) - *(float *)(iVar4 + 0x18),
                   *(float *)(iVar4 + 0x2c) < fVar2 * fVar2 + fVar3 * fVar3)) &&
                  ((*(int *)(param_1 + 0x79c) != 5 || (*(int *)(param_1 + 0x7a0) == 0))))))) {
            iVar6 = iVar6 + 1;
            iVar4 = iVar4 + 0x40;
            if (*(int *)(param_2 + 0x4694) <= iVar6) {
              return;
            }
          }
          if ((DAT_00802818 != -1) && (iVar5 == DAT_00802818)) {
            *(int *)(param_1 + 0x798) = iVar4;
            return;
          }
          *(int *)(param_1 + 0x798) = iVar4;
          *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802814;
          *(undefined1 *)(param_1 + 0xe32) = 0;
          if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (*(float *)(iVar4 + 0x30) == 0.0)) {
            *(undefined4 *)(iVar4 + 0x30) = 0x40800000;
            FUN_00547930(6,param_1 + 0x80,0,0);
          }
        }
      }
    }
  }
  else if (((*(float *)(param_1 + 0x188) < *(float *)(iVar5 + 0x14)) ||
           (*(float *)(iVar5 + 0x28) < *(float *)(param_1 + 0x17c))) ||
          (fVar2 = *(float *)(param_1 + 0x80) - *(float *)(iVar5 + 0x10),
          fVar3 = *(float *)(param_1 + 0x88) - *(float *)(iVar5 + 0x18),
          *(float *)(iVar5 + 0x2c) < fVar2 * fVar2 + fVar3 * fVar3)) {
    *(undefined4 *)(param_1 + 0x798) = 0;
    return;
  }
  return;
}

