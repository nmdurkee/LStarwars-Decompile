/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0b00; label: FUN_005a0b00
 */

undefined4 FUN_005a0b00(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [48];
  undefined1 local_10 [16];
  
  local_4c = 0;
  local_48 = 0;
  iVar4 = 0;
  local_44 = 0;
  if ((((param_1 != 0) && (param_2 != 0)) && (*(char *)(param_1 + 8) != '\0')) &&
     (piVar3 = *(int **)(param_1 + 0x18), piVar3 != (int *)0x0)) {
    do {
      if ((*(byte *)(piVar3 + 8) & 1) == 0) {
        if (piVar3[4] == 0) {
          if (param_5 != 0) {
            uVar2 = FUN_005cf9e0(piVar3 + 1);
            FUN_005b37d0(&local_4c,&local_4c,uVar2);
            goto LAB_005a0bc6;
          }
        }
        else if (param_4 != 0) {
          if (param_3 == 0) {
            iVar1 = piVar3[6];
          }
          else if (param_3 == 1) {
            iVar1 = piVar3[7];
          }
          else {
            iVar1 = *(int *)(piVar3[4] + 0x4c);
          }
          FUN_005526c0(piVar3 + 1,iVar1,local_40,1);
          FUN_005b37d0(&local_4c,&local_4c,local_10);
LAB_005a0bc6:
          iVar4 = iVar4 + 1;
        }
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
    if (iVar4 != 0) {
      FUN_005b3830(param_2,&local_4c,1.0 / (float)iVar4);
      return 1;
    }
  }
  return 0;
}

