/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x58a9b0; label: FUN_0058a9b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0058a9b0(int *param_1,float *param_2,int param_3)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  local_4 = 0;
  iVar1 = 0;
  if (((param_1 != (int *)0x0) || (param_1 = DAT_009553d4, DAT_009553d4 != (int *)0x0)) &&
     ((char)param_1[7] != '\0')) {
    iVar4 = 0;
    pfVar2 = param_2 + 0x14;
    iVar3 = -0x50 - (int)param_2;
    do {
      if (param_3 == 0) {
LAB_0058aa0e:
        if (*(char *)pfVar2 != '\0') goto LAB_0058aa13;
      }
      else {
        *(undefined1 *)pfVar2 = 1;
        if (*param_2 == 0.0) {
          *param_2 = (float)*(ushort *)(*param_1 + 0x10 + iVar4) - 1.0;
          goto LAB_0058aa0e;
        }
LAB_0058aa13:
        local_4 = local_4 + 1;
      }
      pfVar2 = (float *)((int)pfVar2 + 1);
      iVar4 = iVar4 + 0x18;
      param_2 = param_2 + 1;
      iVar1 = local_4;
    } while ((int)(iVar3 + (int)pfVar2) < (int)(uint)*(byte *)(param_1 + 7));
  }
  return iVar1;
}

