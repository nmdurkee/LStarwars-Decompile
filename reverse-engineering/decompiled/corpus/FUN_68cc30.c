/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68cc30; label: FUN_0068cc30
 */

void FUN_0068cc30(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if (DAT_00810ad8 != -1) {
    pcVar3 = *(char **)(DAT_0296209c + DAT_00810ad8 * 4);
    DAT_02924b30 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_0068cbe0,"Type Name");
    if (DAT_02924b30 != 0) {
      uVar2 = FUN_00627c00(0,&local_10,&LAB_006626b0,"Type Name");
      FUN_00618e10(DAT_02924b30,uVar2);
      pcVar4 = (char *)(DAT_02900c84 + 0x4c);
      do {
        cVar1 = *pcVar3;
        *pcVar4 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      *(undefined2 *)(DAT_02900c84 + 0x15a) = 0xf;
      FUN_006279b0(param_1,DAT_02924b30);
      *(int *)(DAT_02924b30 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02924b30 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

