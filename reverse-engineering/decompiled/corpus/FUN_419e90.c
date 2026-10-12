/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x419e90; label: FUN_00419e90
 */

void FUN_00419e90(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short local_8 [4];
  
  iVar5 = 0;
  DAT_029130ec = (uint)(DAT_009553cc == 0);
  local_8[0] = (short)DAT_007f23a4;
  local_8[1] = 1;
  local_8[2] = 0xffff;
  local_8[3] = 0;
  DAT_029130e8 = 1;
  FUN_0062d540(local_8,0,&DAT_00924890,DAT_00924894,DAT_007f23a0);
  FUN_0055b6e0(local_8,0,&DAT_00924890,&DAT_00924894);
  iVar1 = FUN_0055b6c0((int)local_8[0]);
  if ((iVar1 != 0) && (iVar4 = 0, 0 < DAT_00951bbc)) {
    do {
      if (((&DAT_007f44f8)[iVar4 * 8] == '\x03') &&
         ((*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar5) == '\0' &&
          (iVar2 = FUN_005cf5b0(iVar1,*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar5,
                                (&PTR_s_save_icon_007f44fc)[iVar4 * 2],1), iVar2 != 0)))) {
        *(undefined1 *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar5) = 1;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar4 < DAT_00951bbc);
  }
  uVar3 = FUN_0062df80((int)local_8[0]);
  FUN_005935f0(DAT_00856980,uVar3);
  DAT_007f23a8 = DAT_007f23a4;
  DAT_007f23a4 = 0xffffffff;
  return;
}

