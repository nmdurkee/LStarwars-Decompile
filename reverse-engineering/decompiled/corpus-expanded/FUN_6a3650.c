/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3650; label: FUN_006a3650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3650(int *param_1,uint param_2,int param_3)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1[4] <= *param_1 + 4) {
    pvVar1 = _realloc((void *)param_1[2],param_1[4] + 0x100);
    param_1[4] = param_1[4] + 0x100;
    param_1[2] = (int)pvVar1;
    param_1[3] = *param_1 + (int)pvVar1;
  }
  uVar2 = (*(uint *)(&DAT_0076f4e8 + param_3 * 4) & param_2) << (0x20U - (char)param_3 & 0x1f);
  uVar4 = param_3 + param_1[1];
  *(byte *)param_1[3] = *(byte *)param_1[3] | (byte)(uVar2 >> ((char)param_1[1] + 0x18U & 0x1f));
  if ((((7 < (int)uVar4) &&
       (*(char *)(param_1[3] + 1) = (char)(uVar2 >> ((char)param_1[1] + 0x10U & 0x1f)),
       0xf < (int)uVar4)) &&
      (*(char *)(param_1[3] + 2) = (char)(uVar2 >> ((char)param_1[1] + 8U & 0x1f)),
      0x17 < (int)uVar4)) &&
     (*(char *)(param_1[3] + 3) = (char)(uVar2 >> ((byte)param_1[1] & 0x1f)), 0x1f < (int)uVar4)) {
    if (param_1[1] == 0) {
      *(undefined1 *)(param_1[3] + 4) = 0;
    }
    else {
      *(char *)(param_1[3] + 4) = (char)uVar2 << (8U - (char)param_1[1] & 0x1f);
    }
  }
  iVar3 = (int)(uVar4 + ((int)uVar4 >> 0x1f & 7U)) >> 3;
  *param_1 = *param_1 + iVar3;
  param_1[3] = param_1[3] + iVar3;
  param_1[1] = uVar4 & 7;
  return;
}

