/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58ba40; label: FUN_0058ba40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058ba40(int param_1)

{
  short sVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 != 0) {
    iVar5 = 0;
    if (0 < DAT_0093d500) {
      puVar2 = (undefined2 *)(DAT_0093d504 + 0x1070);
      do {
        if ((*(byte *)(puVar2 + -0x73a) & 1) != 0) {
          *puVar2 = 0xffff;
        }
        iVar5 = iVar5 + 1;
        puVar2 = puVar2 + 0x86c;
      } while (iVar5 < DAT_0093d500);
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 4)) {
      iVar6 = param_1 + 8;
      do {
        FUN_005cfc00(iVar6,0);
        uVar3 = FUN_005cffb0(iVar6);
        sVar1 = FUN_0067c760(uVar3);
        *(short *)(iVar6 + 0xe) = sVar1;
        *(undefined4 *)(iVar6 + 0x10) = 0;
        if ((sVar1 != -1) &&
           (iVar4 = FUN_0055ce20((int)*(short *)(iVar6 + 0xc),0,1,0,1), iVar4 != 0)) {
          *(undefined2 *)(iVar4 + 0x1070) = *(undefined2 *)(iVar6 + 0xe);
          *(int *)(iVar6 + 0x10) = iVar4;
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x14;
      } while (iVar5 < *(int *)(param_1 + 4));
    }
  }
  return;
}

