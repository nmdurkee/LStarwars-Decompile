/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59afc0; label: FUN_0059afc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_0059afc0(int param_1,undefined4 *param_2,float param_3,float param_4,float param_5,
            undefined2 param_6,char param_7,undefined4 param_8)

{
  float fVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 uVar4;
  float10 fVar5;
  float10 fVar6;
  
  if ((param_1 == 0) || (puVar2 = *(undefined4 **)(param_1 + 8), puVar2 == (undefined4 *)0x0)) {
    return (undefined4 *)0x0;
  }
  if (param_2 == (undefined4 *)0x0) {
    *puVar2 = DAT_0093b0cc;
    puVar2[1] = DAT_0093b0d0;
    uVar4 = DAT_0093b0d4;
  }
  else {
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    uVar4 = param_2[2];
  }
  puVar2[3] = param_3;
  puVar2[2] = uVar4;
  fVar5 = (float10)param_4;
  puVar2[6] = param_4;
  fVar6 = (float10)param_5;
  puVar2[7] = param_5;
  puVar2[4] = (float)puVar2[1] - _DAT_00801c58;
  fVar1 = (float)puVar2[1] + _DAT_00801c58;
  *(char *)((int)puVar2 + 0x32) = param_7;
  puVar2[5] = fVar1;
  *(undefined2 *)(puVar2 + 0xc) = param_6;
  puVar2[8] = param_8;
  if (param_7 == '\x01') {
    fVar3 = fVar6;
    if (fVar6 < fVar5) goto LAB_0059b05e;
  }
  else {
    fVar3 = (float10)param_3;
    if (param_7 == '\x02') {
      fVar5 = (float10)FUN_005c0240((float)(fVar5 * fVar5 + fVar6 * fVar6));
      goto LAB_0059b05e;
    }
  }
  fVar5 = fVar3;
LAB_0059b05e:
  fVar1 = (float)fVar5;
  puVar2[3] = fVar1;
  FUN_0059a720(*(undefined4 *)(param_1 + 0xc),puVar2,fVar1,fVar1,(int)puVar2 + 0x33,puVar2 + 0xd,
               (int)puVar2 + 0x35,(int)puVar2 + 0x36);
  *(undefined4 *)(param_1 + 8) = puVar2[0xe];
  puVar2[0xe] = *(undefined4 *)(param_1 + 4);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  *(undefined4 **)(param_1 + 4) = puVar2;
  return puVar2;
}

