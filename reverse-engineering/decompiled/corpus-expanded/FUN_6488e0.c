/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x6488e0; label: FUN_006488e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006488e0(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_c [12];
  
  if (*param_1 == '\0') {
    return -1;
  }
  iVar1 = FUN_004f2130(param_1,s_NULL_instance_008101c4,0x10);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      return -1;
    }
    iVar1 = FUN_005da840(param_2);
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        FUN_005da860(local_c,param_2,iVar4);
        iVar2 = FUN_005cfac0(local_c);
        if (iVar2 != 0) {
          uVar3 = FUN_005cfa50(local_c);
          iVar2 = FUN_004f2130(param_1,uVar3,0x10);
          if (iVar2 == 0) {
            return iVar4;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
    return -1;
  }
  return 9999;
}

