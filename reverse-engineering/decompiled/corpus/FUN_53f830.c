/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53f830; label: FUN_0053f830
 */

undefined4 FUN_0053f830(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 0x6d) != '\0') {
    *param_3 = param_2;
    uVar3 = (uint)*(byte *)(param_1 + 0x6d);
    if (*(char *)(param_1 + 0x33) != '\0') {
      if (uVar3 != 0) {
        do {
          *param_3 = *param_3 + 1;
          if (*param_3 == *(ushort *)(param_1 + 0x30) + 1) {
            *param_3 = 0;
          }
          uVar3 = uVar3 - 1;
        } while (0 < (int)uVar3);
      }
      iVar1 = *param_3;
      *param_4 = iVar1 + 1;
      if (iVar1 + 1 == *(ushort *)(param_1 + 0x30) + 1) {
        *param_4 = 0;
      }
      return 1;
    }
    if (uVar3 != 0) {
      do {
        iVar1 = *param_3;
        if ((int)(*(ushort *)(param_1 + 0x30) - 1) <= iVar1) {
          return uVar2;
        }
        *param_3 = iVar1 + 1;
        uVar3 = uVar3 - 1;
        *param_4 = iVar1 + 2;
        uVar2 = 1;
      } while (0 < (int)uVar3);
    }
  }
  return uVar2;
}

