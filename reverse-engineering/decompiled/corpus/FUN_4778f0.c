/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x4778f0; label: FUN_004778f0
 */

void FUN_004778f0(int param_1,uint *param_2,undefined4 param_3)

{
  int *piVar1;
  size_t _Size;
  uint uVar2;
  void *_Dst;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar2;
  *(uint *)(param_1 + 0x2ae0) = uVar2;
  _Dst = (void *)(DAT_00951360 * 0x7c + 3 + *param_2 & 0xfffffffc);
  *param_2 = (uint)_Dst;
  *(void **)(param_1 + 0x2984) = _Dst;
  _Size = DAT_00951360 * 4;
  _memset(_Dst,0,_Size);
  *param_2 = *param_2 + _Size;
  iVar4 = 0;
  if (0 < DAT_00951360) {
    iVar5 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x2984) + iVar4 * 4) = 0;
      iVar3 = (int)*(short *)(DAT_00951354 + 0x8a + iVar5);
      if (((-((*(byte *)(DAT_00951354 + 0x7a + iVar5) & 0x10) != 0) & 10U) != 0) && (iVar3 != -1)) {
        *(uint *)(*(int *)(param_1 + 0x2984) + iVar4 * 4) = *param_2;
        *param_2 = *param_2 + 0x18;
        FUN_00599a40(*(undefined4 *)(*(int *)(param_1 + 0x2984) + iVar4 * 4),iVar3,param_2,param_3,0
                    );
        piVar1 = *(int **)(*(int *)(param_1 + 0x2984) + iVar4 * 4);
        if (*piVar1 == 0) {
          *(undefined4 *)(*(int *)(param_1 + 0x2984) + iVar4 * 4) = 0;
          *param_2 = *param_2 - 0x18;
        }
        else {
          FUN_00599b20(piVar1,10,param_2,param_3);
          *(char *)(*(int *)(*(int *)(param_1 + 0x2984) + iVar4 * 4) + 9) = (char)iVar4;
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x9c;
    } while (iVar4 < DAT_00951360);
  }
  return;
}

