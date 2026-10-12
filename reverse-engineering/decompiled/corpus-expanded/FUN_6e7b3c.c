/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e7b3c; label: FID_conflict:__vscprintf_helper
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    __vscprintf_helper
    __vscwprintf_helper
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

undefined4
FID_conflict___vscprintf_helper(code *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (param_2 == 0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  else {
    local_20 = 0x7fffffff;
    local_18 = 0x42;
    local_1c = 0;
    local_24 = 0;
    uVar2 = (*param_1)(&local_24,param_2,param_3,param_4);
  }
  return uVar2;
}

