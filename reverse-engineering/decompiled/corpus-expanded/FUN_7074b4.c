/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x7074b4; label: ___unDName
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___unDName
   
   Library: Visual Studio 2005 Release */

char * ___unDName(char *param_1,char *param_2,int param_3,int param_4,undefined4 param_5,
                 ushort param_6)

{
  int iVar1;
  UnDecorator local_98 [120];
  char *local_20;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007ed848;
  uStack_c = 0x7074c3;
  if ((param_4 != 0) && (iVar1 = __mtinitlocknum(5), iVar1 != 0)) {
    __lock(5);
    local_8 = (undefined *)0x0;
    DAT_0297cb58 = param_4;
    _DAT_0297cb5c = param_5;
    _DAT_0297cb68 = 0;
    _DAT_0297cb60 = 0;
    _DAT_0297cb64 = 0;
    UnDecorator::UnDecorator
              (local_98,param_1,param_2,param_3,(_func_char_ptr_long *)0x0,(uint)param_6);
    local_20 = UnDecorator::operator_char_(local_98);
    HeapManager::Destructor((HeapManager *)&DAT_0297cb58);
    local_8 = (undefined *)0xfffffffe;
    FUN_0070754e();
    return local_20;
  }
  return (char *)0x0;
}

