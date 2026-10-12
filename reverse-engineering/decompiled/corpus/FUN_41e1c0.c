/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41e1c0; label: FUN_0041e1c0
 */

void FUN_0041e1c0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int in_EAX;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *in_EDX;
  undefined4 *puVar6;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  if (((in_EDX != (undefined4 *)0x0) ||
      ((in_EAX != -1 && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + in_EAX * 4) != 0)))) &&
     (sVar2 = *(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_2 * 2), sVar2 != -1)) {
    iVar3 = *(int *)(DAT_029130e4 + 0x18);
    iVar5 = 0x10;
    if (in_EDX == (undefined4 *)0x0) {
      in_EDX = (undefined4 *)(in_EAX * 0x40 + param_3);
    }
    cVar1 = *(char *)(param_1 + 0x107c);
    puVar6 = local_80;
    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *in_EDX;
      in_EDX = in_EDX + 1;
      puVar6 = puVar6 + 1;
    }
    if (((cVar1 == '\0') || (*(float *)(param_1 + 0x1014) == 2e+06)) ||
       (iVar5 = FUN_00550490(local_80,*(undefined1 *)(param_1 + 0x107b),
                             *(undefined4 *)(param_1 + 0x1014),
                             *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40),
       iVar5 == 0)) {
      puVar4 = (undefined1 *)0x0;
    }
    else {
      puVar4 = local_40;
    }
    FUN_0041cb50(sVar2 * 0x54 + iVar3,param_4,local_80,0,puVar4,0,0,0xffffffff);
  }
  return;
}

