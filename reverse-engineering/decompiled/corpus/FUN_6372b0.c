/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x6372b0; label: FUN_006372b0
 */

void FUN_006372b0(void)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  
  if ((*(int *)(in_EAX + 0x7c) != 0) && (*(char *)(in_EAX + 0x79) != -1)) {
    *(undefined4 *)(in_EAX + 0x24) = 0;
    *(undefined4 *)(in_EAX + 0x30) = 0;
    *(undefined4 *)(in_EAX + 0x28) = 0;
    *(undefined4 *)(in_EAX + 0x34) = 0;
    *(undefined4 *)(in_EAX + 0x2c) = 0;
    *(undefined4 *)(in_EAX + 0x38) = 0;
    *(undefined4 *)(in_EAX + 0x14) = 0;
    *(undefined4 *)(in_EAX + 0x10) = 0;
    pfVar1 = (float *)(in_EAX + 0xc);
    *pfVar1 = 0.0;
    iVar4 = *(char *)(in_EAX + 0x79) * 0x8c + *(int *)(in_EAX + 0x7c);
    fVar2 = *(float *)(PTR_DAT_0080fe0c + *(char *)(iVar4 + 0x7b) * 4);
    *(float *)(in_EAX + 0x24) = *(float *)(in_EAX + 0x24) + fVar2 * *(float *)(iVar4 + 0x24);
    *(float *)(in_EAX + 0x28) = *(float *)(iVar4 + 0x28) * fVar2 + *(float *)(in_EAX + 0x28);
    *(float *)(in_EAX + 0x2c) = *(float *)(iVar4 + 0x2c) * fVar2 + *(float *)(in_EAX + 0x2c);
    *(float *)(in_EAX + 0x30) = *(float *)(iVar4 + 0x30) * fVar2 + *(float *)(in_EAX + 0x30);
    *(float *)(in_EAX + 0x34) = *(float *)(iVar4 + 0x34) * fVar2 + *(float *)(in_EAX + 0x34);
    *(float *)(in_EAX + 0x38) = *(float *)(iVar4 + 0x38) * fVar2 + *(float *)(in_EAX + 0x38);
    *pfVar1 = *(float *)(iVar4 + 0xc) * fVar2 + *pfVar1;
    *(float *)(in_EAX + 0x10) = *(float *)(iVar4 + 0x10) * fVar2 + *(float *)(in_EAX + 0x10);
    *(float *)(in_EAX + 0x14) = fVar2 * *(float *)(iVar4 + 0x14) + *(float *)(in_EAX + 0x14);
    cVar3 = *(char *)(iVar4 + 0x79);
    while (cVar3 != -1) {
      iVar4 = cVar3 * 0x8c + *(int *)(in_EAX + 0x7c);
      fVar2 = *(float *)(PTR_DAT_0080fe0c + *(char *)(iVar4 + 0x7b) * 4);
      *(float *)(in_EAX + 0x24) = *(float *)(in_EAX + 0x24) + fVar2 * *(float *)(iVar4 + 0x24);
      *(float *)(in_EAX + 0x28) = *(float *)(iVar4 + 0x28) * fVar2 + *(float *)(in_EAX + 0x28);
      *(float *)(in_EAX + 0x2c) = *(float *)(iVar4 + 0x2c) * fVar2 + *(float *)(in_EAX + 0x2c);
      *(float *)(in_EAX + 0x30) = *(float *)(iVar4 + 0x30) * fVar2 + *(float *)(in_EAX + 0x30);
      *(float *)(in_EAX + 0x34) = *(float *)(iVar4 + 0x34) * fVar2 + *(float *)(in_EAX + 0x34);
      *(float *)(in_EAX + 0x38) = *(float *)(iVar4 + 0x38) * fVar2 + *(float *)(in_EAX + 0x38);
      *pfVar1 = *(float *)(iVar4 + 0xc) * fVar2 + *pfVar1;
      *(float *)(in_EAX + 0x10) = *(float *)(iVar4 + 0x10) * fVar2 + *(float *)(in_EAX + 0x10);
      *(float *)(in_EAX + 0x14) = fVar2 * *(float *)(iVar4 + 0x14) + *(float *)(in_EAX + 0x14);
      cVar3 = *(char *)(iVar4 + 0x79);
    }
    FUN_005b3b30(pfVar1,pfVar1);
  }
  return;
}

