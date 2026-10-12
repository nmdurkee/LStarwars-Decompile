/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64ab10; label: FUN_0064ab10
 */

int FUN_0064ab10(int param_1,int param_2,int param_3,float param_4,float *param_5,float *param_6,
                uint param_7)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  float local_c;
  float local_8;
  float local_4;
  
  local_14 = 0;
  iVar4 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if (((((((*(byte *)(iVar4 + 0x144) & 1) != 0) && (*(int *)(iVar4 + 0xd4) != param_1)) &&
            ((*(uint *)(iVar4 + 0x108) & param_7) != 0)) &&
           ((*(float *)(iVar4 + 0x8c) <= *param_6 && (*param_5 <= *(float *)(iVar4 + 0x98))))) &&
          ((*(float *)(iVar4 + 0x94) <= param_6[2] &&
           ((param_5[2] <= *(float *)(iVar4 + 0xa0) && (*(float *)(iVar4 + 0x90) <= param_6[1]))))))
         && ((param_5[1] <= *(float *)(iVar4 + 0x9c) && (iVar3 = param_3 + -1, -1 < iVar3)))) {
        iVar2 = param_2 + iVar3 * 0xc;
        do {
          FUN_005b3800(&local_c,iVar2,iVar4 + 0x30);
          fVar1 = param_4 + *(float *)(iVar4 + 0xdc);
          if (local_4 * local_4 + local_c * local_c + local_8 * local_8 <= fVar1 * fVar1) {
            return iVar4;
          }
          iVar3 = iVar3 + -1;
          iVar2 = iVar2 + -0xc;
        } while (-1 < iVar3);
      }
      local_14 = local_14 + 1;
      iVar4 = iVar4 + 0x220;
    } while (local_14 < DAT_0081020c);
  }
  return 0;
}

