/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a14d0; label: FUN_006a14d0
 */

undefined4 FUN_006a14d0(int *param_1,void *param_2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  
  iVar3 = 0;
  _memset(param_2,0,0x70);
  *(int **)((int)param_2 + 0x40) = param_1;
  *(undefined4 *)((int)param_2 + 0x4c) = 0;
  *(undefined4 *)((int)param_2 + 0x44) = 0;
  if (*param_1 != 0) {
    pvVar1 = _calloc(1,0x48);
    *(void **)((int)param_2 + 0x68) = pvVar1;
    *(undefined4 *)((int)pvVar1 + 4) = 0xc61c3c00;
    do {
      if (iVar3 == 7) {
        *(int *)((int)pvVar1 + 0x28) = (int)param_2 + 4;
      }
      else {
        pvVar2 = _calloc(1,0x14);
        *(void **)((int)pvVar1 + iVar3 * 4 + 0xc) = pvVar2;
      }
      FUN_006a3490(*(undefined4 *)((int)pvVar1 + iVar3 * 4 + 0xc));
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
  }
  return 0;
}

