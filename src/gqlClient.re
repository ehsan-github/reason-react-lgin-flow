
/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache(());

/* Create an HTTP Link */
let httpLink =
 ApolloLinks.createHttpLink(~uri="https://dev.immiwork.com/graphql/", ());

let instance = ReasonApollo.createApolloClient(
 ~link=httpLink, 
 ~cache=inMemoryCache, 
 ()
);
