/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b11b0; label: FUN_004b11b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b11b0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined1 local_c [12];
  
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffff7ff;
  uVar3 = FUN_00407e40(param_1,0);
  (**(code **)(PTR_PTR_008040bc + 0x14))(param_1,local_c);
  iVar4 = FUN_005806a0(uVar3,PTR_DAT_00802c54);
  fVar1 = *(float *)(iVar4 + 0x14);
  iVar4 = FUN_005806a0(uVar3,PTR_DAT_00802c54);
  fVar1 = *(float *)(iVar4 + 0x10) * fVar1;
  fVar2 = fVar1 * fVar1;
  iVar4 = param_1 + 0x80;
  iVar5 = FUN_00433df0(param_1,iVar4,local_c,fVar1,fVar2,0,1,0,uVar3);
  if (iVar5 == 0) {
    if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) ||
       (iVar5 = FUN_0046a450(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_00802c54,param_1,
                             iVar4,local_c,fVar1,fVar2,1,0,uVar3), iVar5 != 0)) goto LAB_004b132e;
    iVar5 = FUN_0056a240(param_1,iVar4,local_c,fVar1,fVar2,1,0,uVar3);
    if (iVar5 != 0) {
      FUN_004a5f70(param_1,iVar5);
      goto LAB_004b132e;
    }
    iVar5 = FUN_00572020(param_1,iVar4,local_c,fVar1,fVar2,1,uVar3);
    if (iVar5 != 0) {
      FUN_004a5fe0(param_1,iVar5);
      goto LAB_004b132e;
    }
    iVar5 = FUN_00433df0(param_1,iVar4,local_c,fVar1,fVar2,0x200,1,0,uVar3);
    if (iVar5 == 0) goto LAB_004b132e;
  }
  FUN_004a5ec0(param_1,iVar5);
LAB_004b132e:
  *(short *)(param_1 + 0x7aa) = (short)param_2;
  *(undefined1 *)(param_1 + 0x7b5) = 10;
  fVar6 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)(short)param_2,0,0,
                                param_2 != 0x57);
  *(float *)(param_1 + 0x77c) = (float)fVar6;
  FUN_0062e650(param_1 + 8,0xffffffff);
  *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 0x10;
  fVar6 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),1);
  uVar3 = 1;
  if (fVar6 <= (float10)1.0) {
    uVar3 = 3;
  }
  uVar3 = FUN_00407e40(param_1,0,uVar3);
  FUN_0049d430(uVar3);
  *(char *)(param_1 + 0xe3b) = *(char *)(param_1 + 0xe3b) + '\x01';
  *(undefined4 *)(param_1 + 0xd58) = 0;
  FUN_0058d430(param_1);
  return;
}

