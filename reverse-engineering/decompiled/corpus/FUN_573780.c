/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573780; label: FUN_00573780
 */

int * FUN_00573780(float param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  float10 fVar6;
  int local_10;
  int *local_c;
  int *local_8;
  
  iVar1 = (int)param_1;
  iVar3 = *(int *)((int)param_1 + 300);
  if ((iVar3 != 0) && (piVar5 = *(int **)(iVar3 + 0x80), piVar5 != (int *)0x0)) {
    param_1 = 1e+09;
    local_8 = (int *)0x0;
    local_c = (int *)0x0;
    local_10 = 0;
    if (*(char *)(iVar3 + 0x7f) != '\0') {
      do {
        iVar3 = 0;
        piVar4 = piVar5;
        if ((short)piVar5[0x78] != 0) {
          do {
            if (((int)(short)piVar4[0xb] == *(int *)(iVar1 + 0x11c)) && (*piVar4 == param_2)) {
              if (piVar4[1] == 0) {
                if (param_4 != (undefined4 *)0x0) {
                  *param_4 = piVar4;
                }
                return piVar5;
              }
              iVar2 = FUN_0055a360(*(undefined4 *)(iVar1 + 0x2ac8),piVar4[1]);
              if (iVar2 != 0) {
                fVar6 = (float10)FUN_005b3c50(param_3,iVar2,0);
                if ((float)fVar6 < param_1) {
                  param_1 = (float)fVar6;
                  local_c = piVar4;
                  local_8 = piVar5;
                }
              }
            }
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 0xc;
          } while (iVar3 < (int)(uint)*(ushort *)(piVar5 + 0x78));
        }
        local_10 = local_10 + 1;
        piVar5 = piVar5 + 0x7a;
      } while (local_10 < (int)(uint)*(byte *)(*(int *)(iVar1 + 300) + 0x7f));
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_c;
    }
    return local_8;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  return (int *)0x0;
}

