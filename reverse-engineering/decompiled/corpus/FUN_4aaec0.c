/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4aaec0; label: FUN_004aaec0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aaec0(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int in_EAX;
  int iVar4;
  float10 fVar5;
  undefined4 local_c;
  
  local_c = 0;
  uVar3 = local_c;
  if (((((*(char *)(in_EAX + 0xe38) != '\0') &&
        (((*(short *)(in_EAX + 0x1064) != DAT_007f1b3c || (*(int *)(PTR_DAT_00802c54 + 300) == 0))
         || (uVar3 = _DAT_007fc178, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af68)))) &&
       (((iVar4 = FUN_0062f1a0(in_EAX + 8), *(char *)(in_EAX + 0x281) != '\0' ||
         (uVar3 = local_c, 0.0 < *(float *)(in_EAX + 0xd24))) && (uVar3 = local_c, iVar4 != -1))))
      && ((iVar4 != 3 && (iVar4 != 0x23)))) &&
     ((iVar4 != 5 &&
      (((iVar4 != 0x6a && (*(char *)(in_EAX + 0x7b5) != '\x17')) &&
       (*(char *)(in_EAX + 0x7b5) != '=')))))) {
    uVar3 = 0x3f800000;
  }
  local_c = uVar3;
  fVar1 = *(float *)(in_EAX + 0xd30);
  fVar5 = (float10)FUN_0054fad0(*(undefined4 *)(in_EAX + 0xd30),local_c,_DAT_00925018 * 5.0);
  fVar2 = (float)fVar5;
  *(float *)(in_EAX + 0xd30) = fVar2;
  if (((fVar1 != 0.0) || (fVar2 <= 0.0)) && ((fVar1 != 1.0 || (1.0 <= fVar2)))) {
    return;
  }
  FUN_00681f40("DDekaShOn",in_EAX + 0x80);
  return;
}

