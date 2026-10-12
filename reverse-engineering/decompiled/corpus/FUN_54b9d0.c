/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54b9d0; label: FUN_0054b9d0
 */

void FUN_0054b9d0(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = DAT_00926c3c;
  iVar5 = 0;
  piVar3 = param_1;
  do {
    if (piVar3 == (int *)0x0) {
      return;
    }
    if (((short *)*param_1 != (short *)0x0) && (sVar2 = (short)param_1[1], sVar2 != -1)) {
      iVar5 = (int)sVar2;
      if ((param_2 <= iVar5) && (iVar5 <= param_3)) {
        *(short *)(param_1 + 1) = sVar2;
        *(short *)*param_1 = sVar2;
      }
      iVar5 = iVar5 + 1;
      param_1 = param_1 + 2;
    }
    if (*param_1 == 0) {
      return;
    }
    do {
      if ((short)param_1[1] != -1) break;
      if ((iVar5 < param_2) || (param_3 < iVar5)) {
        *(undefined2 *)(param_1 + 1) = 0;
        *(undefined2 *)*param_1 = 0;
      }
      else {
        *(short *)(param_1 + 1) = (short)iVar5;
        *(short *)*param_1 = (short)iVar5;
        puVar1 = (uint *)(iVar4 + ((int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)iVar5 & 0x1f);
      }
      param_1 = param_1 + 2;
      iVar5 = iVar5 + 1;
    } while (*param_1 != 0);
    piVar3 = (int *)*param_1;
  } while( true );
}

