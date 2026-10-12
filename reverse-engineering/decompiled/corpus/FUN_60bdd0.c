/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60bdd0; label: FUN_0060bdd0
 */

void FUN_0060bdd0(uint param_1,rsize_t param_2)

{
  uint uVar1;
  undefined4 *_Dst;
  void *_Src;
  undefined4 *puVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0074fb80;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  uVar4 = param_1 | 0xf;
  if (uVar4 != 0xffffffff) {
    uVar1 = *(uint *)(in_ECX + 0x18);
    uVar3 = uVar1 >> 1;
    param_1 = uVar4;
    if ((uVar4 / 3 < uVar3) && (uVar1 <= -uVar3 - 2)) {
      param_1 = uVar3 + uVar1;
    }
  }
  local_8 = 0;
  _Dst = (undefined4 *)FUN_00609ff0(param_1 + 1);
  local_8 = 0xffffffff;
  if (param_2 != 0) {
    if (*(uint *)(in_ECX + 0x18) < 0x10) {
      _Src = (void *)(in_ECX + 4);
    }
    else {
      _Src = *(void **)(in_ECX + 4);
    }
    _memcpy_s(_Dst,param_1 + 1,_Src,param_2);
  }
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    _free(*(void **)(in_ECX + 4));
  }
  puVar2 = (undefined4 *)(in_ECX + 4);
  *(undefined1 *)puVar2 = 0;
  *puVar2 = _Dst;
  *(uint *)(in_ECX + 0x18) = param_1;
  *(rsize_t *)(in_ECX + 0x14) = param_2;
  if (0xf < param_1) {
    puVar2 = _Dst;
  }
  *(undefined1 *)((int)puVar2 + param_2) = 0;
  *unaff_FS_OFFSET = local_10;
  return;
}

