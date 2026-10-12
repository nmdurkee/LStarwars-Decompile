/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4b13e0; label: FUN_004b13e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b13e0(int param_1)

{
  char cVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  float10 fVar5;
  undefined4 uVar6;
  
  cVar1 = *(char *)(in_ECX + 0x7b5);
  if (cVar1 == '%') {
    if (in_EAX == 0) {
      if ((param_1 != 0) && (*(short *)(in_ECX + 0x7aa) == 0x58)) {
        *(undefined1 *)(in_ECX + 0x7b1) = 1;
      }
    }
    else {
      *(undefined1 *)(in_ECX + 0x7b1) = 2;
    }
    iVar3 = FUN_0062f150(in_ECX + 8,(int)*(short *)(in_ECX + 0x7aa),1,0);
    if (iVar3 != 0) {
      fVar2 = *(float *)(in_ECX + 0x77c) - _DAT_00925018;
      *(float *)(in_ECX + 0x77c) = fVar2;
      if (fVar2 <= 0.0) {
        *(undefined1 *)(in_ECX + 0x7b5) = 0xff;
        FUN_0062e650(in_ECX + 8,0xffffffff);
        *(undefined4 *)(in_ECX + 0x70) = 0;
        *(undefined4 *)(in_ECX + 0x68) = 0;
        iVar3 = FUN_00499500();
        if (iVar3 != 0) {
          *(undefined2 *)(in_ECX + 0x27a) = *(undefined2 *)(in_ECX + 0x5a);
          *(undefined2 *)(in_ECX + 0x58) = *(undefined2 *)(in_ECX + 0x5a);
        }
        if (*(char *)(in_ECX + 0x7b1) == '\x02') {
          iVar3 = FUN_005a86a0(in_ECX + 0x7f4);
          if (iVar3 != 0) {
            if ((*(short *)(in_ECX + 0x7aa) != 0x58) ||
               (*(float *)(*(int *)(in_ECX + 0xca4) + 0x28) <= 0.0)) {
              FUN_004b11b0();
            }
            else {
              FUN_0058d430();
              uVar6 = 3;
              uVar4 = FUN_00407e40();
              FUN_0049d430(uVar4,uVar6);
            }
            fVar5 = (float10)FUN_0062e040((int)*(short *)(in_ECX + 0x1064),
                                          (int)*(short *)(in_ECX + 0x7aa),0,0,1);
            *(float *)(in_ECX + 0xd58) = (float)fVar5;
            return;
          }
        }
        if (*(char *)(in_ECX + 0x7b1) == '\x01') {
          FUN_00561ba0();
          return;
        }
      }
    }
  }
  else if (((((*(byte *)(in_ECX + 0x1fc) & 0x80) != 0) && (*(char *)(in_ECX + 0x281) != '\0')) &&
           ((cVar1 == -1 || ((cVar1 == '\n' && (*(short *)(in_ECX + 0x7aa) != 0x57)))))) &&
          (iVar3 = *(int *)(*(int *)(in_ECX + 0x54) + 0x24),
          *(float *)(*(int *)(in_ECX + 0xca4) + 0x28) <=
          (*(float *)(iVar3 + 0x1c) + *(float *)(iVar3 + 0x18)) * 0.5)) {
    iVar3 = FUN_0057fec0();
    *(int *)(in_ECX + 0xd04) = iVar3;
    if ((iVar3 != 0) && (in_EAX != 0)) {
      FUN_0049e7f0();
    }
  }
  return;
}

