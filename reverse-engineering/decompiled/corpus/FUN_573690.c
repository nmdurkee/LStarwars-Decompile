/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573690; label: FUN_00573690
 */

void FUN_00573690(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar2 = param_1;
  iVar6 = *(int *)(param_1 + 300);
  iVar5 = 0;
  if (((iVar6 != 0) && (iVar4 = *(int *)(iVar6 + 0x80), iVar4 != 0)) &&
     (param_1 = 0, *(char *)(iVar6 + 0x7f) != '\0')) {
    do {
      puVar7 = (undefined4 *)(iVar5 + iVar4);
      iVar6 = 0;
      if (*(short *)(puVar7 + 0x78) != 0) {
        do {
          uVar3 = FUN_0055a020(*(undefined4 *)(iVar2 + 0x2ac8),0xffffffff,puVar7 + 5);
          *puVar7 = uVar3;
          puVar7[1] = 0;
          puVar7[2] = 0;
          puVar7[3] = 0;
          puVar7[4] = 0;
          pcVar1 = (char *)(puVar7 + 7);
          if (*pcVar1 != '\0') {
            if (*(char *)((int)puVar7 + 0x2e) == '\0') {
              uVar3 = FUN_0055a020(*(undefined4 *)(iVar2 + 0x2ac8),0xffffffff,pcVar1);
              puVar7[1] = uVar3;
            }
            else {
              FUN_005cf5b0(*(undefined4 *)(iVar2 + 0x13c),puVar7 + 2,pcVar1,1);
            }
          }
          iVar4 = *(int *)(*(int *)(iVar2 + 300) + 0x80);
          iVar6 = iVar6 + 1;
          puVar7 = puVar7 + 0xc;
        } while (iVar6 < (int)(uint)*(ushort *)(iVar5 + 0x1e0 + iVar4));
      }
      param_1 = param_1 + 1;
      iVar5 = iVar5 + 0x1e8;
    } while (param_1 < (int)(uint)*(byte *)(*(int *)(iVar2 + 300) + 0x7f));
  }
  return;
}

