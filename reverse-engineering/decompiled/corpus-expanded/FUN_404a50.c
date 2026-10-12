/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x404a50; label: FUN_00404a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00404a50(int param_1,undefined4 *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  short sVar4;
  float10 fVar5;
  float10 fVar6;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    cVar2 = *(char *)(param_1 + 0xae);
    if (cVar2 < '\x05') {
      *(byte *)(param_1 + 0xaf) = *(byte *)(param_1 + 0xaf) | 1;
      *(undefined4 *)(param_1 + 0xa0) = *param_2;
      iVar1 = param_1 + 0xa0;
      *(undefined4 *)(param_1 + 0xa4) = param_2[1];
      local_64 = *(undefined4 *)(param_1 + 0x70);
      uVar3 = param_2[2];
      *(undefined4 *)(param_1 + 0xb0) = 0;
      *(char *)(param_1 + 0xae) = cVar2 + '\x01';
      local_60 = *(undefined4 *)(param_1 + 0x74);
      *(undefined4 *)(param_1 + 0xa8) = uVar3;
      local_5c = *(undefined4 *)(param_1 + 0x78);
      local_58 = local_64;
      local_54 = local_60;
      local_50 = local_5c;
      FUN_005b3920(local_4c,iVar1,&local_64);
      FUN_005b3b30(local_4c,local_4c);
      FUN_005b44e0(local_40);
      fVar5 = (float10)FUN_005bec80(iVar1);
      fVar6 = (float10)FUN_005bec80(&local_64);
      fVar5 = (float10)FUN_005b39e0(iVar1,&local_64,(float)(fVar6 * (float10)(double)fVar5));
      fVar5 = (float10)FUN_00403cb0((float)fVar5);
      sVar4 = FUN_00403cf0((float)fVar5);
      FUN_005b4770(local_40,(0x4000 - (short)(0x4000 - sVar4)) * 2,local_4c);
      FUN_005b3200(&local_64,&local_64,local_40);
      fVar5 = (float10)FUN_005b3b30(&local_58,&local_58);
      FUN_005b3b30(&local_64,&local_64);
      FUN_005b37d0(&local_64,&local_64,&local_58);
      FUN_005b3b30(&local_64,&local_64);
      FUN_005b3830(&local_64,&local_64,(float)fVar5 * 0.8);
      fVar5 = (float10)FUN_0054fad0(*(undefined4 *)(param_1 + 0x70),local_64,0x41200000);
      *(float *)(param_1 + 0x70) = (float)fVar5;
      fVar5 = (float10)FUN_0054fad0(*(undefined4 *)(param_1 + 0x74),local_60,0x41200000);
      *(float *)(param_1 + 0x74) = (float)fVar5;
      fVar5 = (float10)FUN_0054fad0(*(undefined4 *)(param_1 + 0x78),local_5c,0x41200000);
      *(float *)(param_1 + 0x78) = (float)fVar5;
      return 1;
    }
    *(byte *)(param_1 + 0xaf) = *(byte *)(param_1 + 0xaf) & 0xfe;
    *(char *)(param_1 + 0xae) = cVar2 + -1;
    *(undefined4 *)(param_1 + 0xa0) = DAT_0093b0cc;
    *(undefined4 *)(param_1 + 0xa4) = DAT_0093b0d0;
    *(undefined4 *)(param_1 + 0xa8) = DAT_0093b0d4;
  }
  return 0;
}

