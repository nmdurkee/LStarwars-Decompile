/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x555fb0; label: FUN_00555fb0
 */

int FUN_00555fb0(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = 1.5625;
  iVar2 = 0;
  local_10 = 0;
  iVar4 = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0') {
    iVar3 = 0;
    do {
      bVar1 = *(byte *)(*(int *)(param_1 + 0x46e0) + 0xac + iVar3);
      iVar4 = *(int *)(param_1 + 0x46e0) + iVar3;
      if (((bVar1 & 1) != 0) && ((bVar1 & 0x26) == 0)) {
        if (param_3 == 0) {
          if ((*(byte *)(iVar4 + 0x84) & 8) == 0) goto LAB_00556013;
        }
        else if ((*(byte *)(iVar4 + 0x84) & 8) != 0) {
LAB_00556013:
          local_c = *(undefined4 *)(iVar4 + 0x5c);
          local_8 = *(undefined4 *)(iVar4 + 0x60);
          local_4 = *(undefined4 *)(iVar4 + 100);
          fVar5 = (float10)FUN_005b3c50(param_2,&local_c,0);
          if ((float)fVar5 < local_14) {
            local_14 = (float)fVar5;
            local_10 = iVar4;
          }
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x304;
      iVar4 = local_10;
    } while (iVar2 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
  }
  return iVar4;
}

