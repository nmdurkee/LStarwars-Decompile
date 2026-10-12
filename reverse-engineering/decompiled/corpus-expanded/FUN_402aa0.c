/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x402aa0; label: FUN_00402aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00402aa0(int *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_40 [16];
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    *(byte *)(iVar1 + 0x62) =
         *(byte *)(iVar1 + 0x62) ^ ((param_2 != 0) * '\x02' ^ *(byte *)(iVar1 + 0x62)) & 2;
    bVar2 = *(byte *)(iVar1 + 0x62) >> 1 & 1;
    if ((bVar2 != 0) && (*(short *)(iVar1 + 0x60) == -1)) {
      uVar4 = FUN_005cffb0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x480);
      FUN_0067c760(uVar4);
      FUN_005b44e0(local_40);
      FUN_005b4670(local_40,0);
      FUN_005b4f70(local_40,*(undefined2 *)(iVar1 + 0x5c));
      FUN_005b4900(local_40,iVar1 + 0x10);
      puVar6 = local_40;
      puVar7 = (undefined4 *)(iVar1 + 0x1c);
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      uVar3 = FUN_0067c4f0((undefined4 *)(iVar1 + 0x1c),4);
      *(undefined2 *)(iVar1 + 0x60) = uVar3;
      return;
    }
    if ((bVar2 == 0) && (*(short *)(iVar1 + 0x60) != -1)) {
      FUN_0067c930((int)*(short *)(iVar1 + 0x60));
      *(undefined2 *)(iVar1 + 0x60) = 0xffff;
    }
  }
  return;
}

