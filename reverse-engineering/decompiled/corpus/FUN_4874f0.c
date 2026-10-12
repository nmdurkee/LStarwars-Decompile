/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x4874f0; label: FUN_004874f0
 */

void FUN_004874f0(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  float10 fVar3;
  undefined1 local_c [12];
  
  iVar2 = 0;
  if (0 < DAT_0093d500) {
    puVar1 = (uint *)(DAT_0093d504 + 0x1fc);
    do {
      if (((((*puVar1 & 1) != 0) && ((*puVar1 & 0x1000) != 0)) &&
          (*(char *)((int)puVar1 + 0x5b9) == '<')) && (puVar1[0x165] == param_2)) {
        return;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x436;
    } while (iVar2 < DAT_0093d500);
  }
  if ((((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 1) != 0)) &&
      ((param_2 != 0 &&
       (((*(byte *)(param_2 + 0x1fc) & 1) != 0 && (*(int *)(param_1 + 0xcd0) == 0)))))) &&
     (*(int *)(param_2 + 0xcd0) == 0)) {
    *(undefined1 *)(param_1 + 0x7b5) = 0x3c;
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x18) == 0) {
      fVar3 = (float10)0.5;
      *(undefined2 *)(param_1 + 0x7aa) = 5;
    }
    else {
      FUN_0062e650(param_1 + 8,0xffffffff);
      *(undefined2 *)(param_1 + 0x7aa) = 6;
      fVar3 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),6,0,0,1);
    }
    *(float *)(param_1 + 0x784) = (float)fVar3;
    if ((*(short *)(param_2 + 0x1064) == DAT_007f1914) &&
       (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) {
      FUN_004871a0(param_2,local_c);
      fVar3 = (float10)FUN_004c99b0(param_1 + 0x5c,local_c);
      *(float *)(param_1 + 0x784) = (float)((fVar3 + fVar3) * (float10)*(float *)(param_1 + 0x784));
    }
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x74c) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 100);
    *(undefined2 *)(param_1 + 0x7a6) = *(undefined2 *)(param_1 + 0x27a);
    *(uint *)(param_1 + 0x790) = param_2;
    *(undefined4 *)(param_1 + 0xea4) = 0;
    *(undefined4 *)(param_2 + 0xea4) = 0;
    FUN_00547f30(param_1,0);
  }
  return;
}

