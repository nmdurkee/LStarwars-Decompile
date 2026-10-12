/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a54b0; label: FUN_004a54b0
 */

void FUN_004a54b0(float param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  int iVar3;
  
  if ((param_2 == 0) ||
     (iVar2 = *(int *)(*(int *)(in_ECX + 0x54) + 0x24),
     (*(float *)(iVar2 + 0x18) + *(float *)(iVar2 + 0x14)) * 0.5 < param_1)) {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x54) + 0x24);
    if ((*(float *)(iVar2 + 0x1c) + *(float *)(iVar2 + 0x18)) * 0.5 < param_1) {
      if ((in_EDX == 0) ||
         (((*(float *)(in_ECX + 0xd3c) != 1.0 && (*(char *)(in_ECX + 0xe33) != '\x01')) ||
          (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x5c) == 0)))) {
        *(undefined2 *)(in_ECX + 0x42) = 3;
      }
      else {
        *(undefined2 *)(in_ECX + 0x42) = 0x17;
      }
    }
    else if (((in_EDX == 0) ||
             ((*(float *)(in_ECX + 0xd3c) != 1.0 && (*(char *)(in_ECX + 0xe33) != '\x01')))) ||
            (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x100) == 0)) {
      if ((*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x140) == 0) ||
         ((*(uint *)(in_ECX + 0xef0) & 0x4000) == 0)) {
        *(undefined2 *)(in_ECX + 0x42) = 0;
      }
      else {
        *(undefined2 *)(in_ECX + 0x42) = 0x50;
      }
    }
    else {
      *(undefined2 *)(in_ECX + 0x42) = 0x40;
    }
  }
  else if ((in_EDX == 0) ||
          (((*(float *)(in_ECX + 0xd3c) != 1.0 && (*(char *)(in_ECX + 0xe33) != '\x01')) ||
           (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0xfc) == 0)))) {
    *(undefined2 *)(in_ECX + 0x42) = 4;
  }
  else {
    *(undefined2 *)(in_ECX + 0x42) = 0x3f;
  }
  if (((*(int *)(in_ECX + 0xcbc) != 0) && ((*(byte *)(*(int *)(in_ECX + 0xcbc) + 0xc) & 0x40) != 0))
     && ((*(char *)(in_ECX + 0x7b5) != 'C' || (*(char *)(in_ECX + 0x7b6) != '\x05')))) {
    sVar1 = *(short *)(in_ECX + 0x42);
    if ((sVar1 == 4) && (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x318) != 0)) {
      *(undefined2 *)(in_ECX + 0x42) = 0xc6;
    }
    else if ((sVar1 == 0) && (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x31c) != 0)) {
      *(undefined2 *)(in_ECX + 0x42) = 199;
    }
    else if ((sVar1 == 3) && (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 800) != 0)) {
      *(undefined2 *)(in_ECX + 0x42) = 200;
    }
  }
  iVar3 = 0;
  iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + *(short *)(in_ECX + 0x42) * 4);
  do {
    if ((iVar2 != 0) || (2 < iVar3)) {
      return;
    }
    sVar1 = *(short *)(in_ECX + 0x42);
    if (sVar1 == 4) {
LAB_004a5672:
      *(undefined2 *)(in_ECX + 0x42) = 0;
    }
    else if (sVar1 == 0) {
      *(undefined2 *)(in_ECX + 0x42) = 3;
    }
    else if (sVar1 == 3) goto LAB_004a5672;
    iVar3 = iVar3 + 1;
    iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + *(short *)(in_ECX + 0x42) * 4);
  } while( true );
}

