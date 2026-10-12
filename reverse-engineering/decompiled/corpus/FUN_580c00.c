/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580c00; label: FUN_00580c00
 */

void FUN_00580c00(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = FUN_0055f450();
  iVar2 = 0;
  do {
    if ((*(uint *)(param_1 + 0xf0) & 0x40000200) == 0) {
      if (param_3 != -1) goto LAB_00580c3b;
LAB_00580c3f:
      FUN_0062c560(*(undefined4 *)(iVar1 + 0x134),(int)*(short *)(param_1 + 0xfc),
                   param_2 + iVar2 * 0xc);
    }
    else {
      if (param_3 == -1) {
        bVar3 = iVar2 == 1;
      }
      else {
LAB_00580c3b:
        bVar3 = param_3 == iVar2;
      }
      if (bVar3) goto LAB_00580c3f;
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      if (*(short *)(param_1 + 0xfe) != -1) {
        FUN_00571b60(*(undefined4 *)(iVar1 + 0x138),(int)*(short *)(param_1 + 0xfe),param_1 + 0x88);
      }
      return;
    }
  } while( true );
}

