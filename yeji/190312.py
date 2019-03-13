def numUniqueEmails( inputs):
        n=len(inputs)
        emails=[]
        addresses=[]
        for i in range(n):
            check=inputs[i]
            mid=check.index('@')
            if check[mid+1:] not in emails:
                emails.append(check[mid+1:])
                addid=len(emails)-1
                addresses.append([])
            else: addid=emails.index(check[mid+1:])
            if '+' in check[:mid]:
                email=check[:check.index('+')]
            else: email=check[:mid]
            email=email.replace('.','')
            if email not in addresses[addid]:
                addresses[addid].append(email)
            print(i,addid)
            '''
            if addid==len(emails)-1:
                addresses.append([email])
            else:
                addresses[addid].append(email)'''
        result=[len(i) for i in addresses]
        print(emails,addresses)
        print(result)
        return sum(result)
numUniqueEmails(["test.ema.il+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com","testemail+davi@lee.tcode.com"])
