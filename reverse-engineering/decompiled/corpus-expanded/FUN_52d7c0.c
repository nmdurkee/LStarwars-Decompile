/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52d7c0; label: FUN_0052d7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0052d7c0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_4;
  
  iVar1 = param_4;
  local_4 = 0.0;
  iVar4 = 0;
  iVar5 = 0;
  if (((param_1 != 0) && (param_6 != 0)) && (iVar6 = 0, 0 < param_5)) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(iVar1 + iVar6 * 4),&DAT_00757f40);
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(iVar1 + iVar6 * 4),&DAT_00757d6c);
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(iVar1 + iVar6 * 4),"length");
          if (iVar2 != 0) {
            fVar7 = (float10)FUN_00514920(param_3,param_2,iVar2 + 7);
            local_4 = (float)fVar7;
          }
        }
        else {
          iVar4 = iVar2 + 3;
        }
      }
      else {
        iVar5 = iVar2 + 5;
      }
      iVar2 = param_1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_5);
    if (((iVar5 != 0) && (iVar4 != 0)) &&
       (puVar3 = (uint *)FUN_0051adf0(param_1,*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),iVar5,
                                      iVar4,&param_1), puVar3 != (uint *)0x0)) {
      puVar3[8] = (uint)local_4;
      if ((local_4 != 0.0) &&
         (iVar5 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + 8) + 0x7c),
         *(float *)(iVar5 + 0x10) + *(float *)(iVar5 + 0x10) + local_4 < (float)puVar3[7])) {
        *puVar3 = *puVar3 | 0x8000000;
        puVar3[1] = puVar3[1] | 0x8000000;
        return 1;
      }
      *puVar3 = *puVar3 & 0xf7ffffff;
      puVar3[1] = puVar3[1] & 0xf7ffffff;
    }
  }
  return 1;
}

