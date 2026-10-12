/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x513820; label: FUN_00513820
 */

void FUN_00513820(int param_1)

{
  size_t _Size;
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  void *_Dst;
  
  if ((DAT_0092221c != 0) && (*(int *)(DAT_0092221c + 0xc) == 0)) {
    *(uint *)(DAT_0092221c + 0x3c) = *(uint *)(DAT_0092221c + 0x3c) & 0xfffffffb;
    while( true ) {
      iVar3 = FUN_004fc5b0(param_1);
      if (iVar3 == 0) break;
      while( true ) {
        iVar3 = FUN_004f7fb0(param_1);
        if (iVar3 == 0) break;
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
        if (iVar3 == 0) goto LAB_00513979;
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Script");
        puVar2 = DAT_00922218;
        piVar1 = DAT_00922214;
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Source");
          if (iVar3 != 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Global");
            if (iVar3 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"Level");
              if (iVar3 != 0) {
                *(uint *)(DAT_0092221c + 0x3c) = *(uint *)(DAT_0092221c + 0x3c) | 4;
              }
            }
            else {
              *(uint *)(DAT_0092221c + 0x3c) = *(uint *)(DAT_0092221c + 0x3c) & 0xfffffffb;
            }
          }
        }
        else {
          iVar3 = iVar3 + 7;
          _Dst = (void *)0x0;
          if (iVar3 != 0) {
            iVar4 = FUN_004f1ff0(iVar3);
            if (iVar4 != 0) {
              _Size = iVar4 + 1;
              if (((piVar1 == (int *)0x0) || (puVar2 == (uint *)0x0)) ||
                 (*puVar2 <= *piVar1 + _Size)) {
                FUN_00512850();
              }
              else {
                uVar5 = *piVar1 + 0xf;
                _Dst = (void *)(uVar5 & 0xfffffff0);
                *piVar1 = (uVar5 & 0xfffffff0) + _Size;
                _memset(_Dst,0,_Size);
              }
              FUN_004f1f10(_Dst,iVar3);
            }
          }
          *(void **)(DAT_0092221c + 0xc) = _Dst;
        }
      }
    }
LAB_00513979:
    if (*(int *)(DAT_0092221c + 0xc) != 0) {
      *(uint *)(DAT_0092221c + 0x3c) = *(uint *)(DAT_0092221c + 0x3c) | 2;
    }
  }
  return;
}

